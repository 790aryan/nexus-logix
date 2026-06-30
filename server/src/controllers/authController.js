const authService = require("../services/authService");
const cookieOptions = require("../utils/cookieOptions");

/**
 * Register User
 */
const register = async (req, res, next) => {
    try {

        const { user, token } = await authService.registerUser(req.body);

        res.cookie("token", token, cookieOptions);

        return res.status(201).json({
            success: true,
            message: "User registered successfully",
            data: {
                user,
            },
        });

    } catch (error) {
        next(error);
    }
};

/**
 * Login User
 */
const login = async (req, res, next) => {
    try {

        const { user, token } = await authService.loginUser(req.body);

        res.cookie("token", token, cookieOptions);

        return res.status(200).json({
            success: true,
            message: "Login successful",
            data: {
                user,
            },
        });

    } catch (error) {
        next(error);
    }
};

/**
 * Logout User
 */
const logout = (req, res) => {

    res.clearCookie("token", cookieOptions);

    return res.status(200).json({
        success: true,
        message: "Logged out successfully",
    });

};

/**
 * Current Logged User
 */
const me = async (req, res, next) => {
    try {

        const user = await authService.getCurrentUser(req.user.id);

        return res.status(200).json({
            success: true,
            data: {
                user,
            },
        });

    } catch (error) {
        next(error);
    }
};

module.exports = {
    register,
    login,
    logout,
    me,
};