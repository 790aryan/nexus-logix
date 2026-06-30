const User = require("../models/User");
const generateToken = require("../utils/generateToken");
const AppError = require("../errors/AppError");
/**
 * Register a new user
 */
const registerUser = async ({ name, email, password }) => {

    // Check if email already exists
    const existingUser = await User.findOne({ email });

    if (existingUser) {
        throw new AppError(
            "User with this email already exists",
            409
        );
    }

    // Create user
    const user = await User.create({
        name,
        email,
        password,
    });

    // Fetch again without password
    const createdUser = await User.findById(user._id);

    // Generate JWT
    const token = generateToken(createdUser);

    return {
        user: createdUser,
        token,
    };
};

/**
 * Login existing user
 */
const loginUser = async ({ email, password }) => {
    // Password is hidden by default (select:false)
    const user = await User.findOne({ email }).select("+password");

    if (!user) {
        throw new AppError(
            "Invalid email or password",
            401
        );
    }

    // Compare password
    const isPasswordCorrect = await user.comparePassword(password);

    if (!isPasswordCorrect) {
        throw new AppError(
            "Invalid email or password",
            401
        );
    }

    // Update last login
    user.lastLogin = new Date();
    await user.save();

    // Remove password before returning
    user.password = undefined;

    // Generate JWT
    const token = generateToken(user);

    return {
        user,
        token,
    };
};

/**
 * Get current logged in user
 */
const getCurrentUser = async (userId) => {
    const user = await User.findById(userId);

    if (!user) {
        throw new AppError(
            "User not found",
            404
        );
    }

    return user;
};

module.exports = {
    registerUser,
    loginUser,
    getCurrentUser,
};