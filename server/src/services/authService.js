const User = require('../models/User');
const jwt = require('jsonwebtoken');

const generateToken = (userId, role) => {
    return jwt.sign({ userId, role }, process.env.JWT_SECRET, { expiresIn: '7d' });
};

exports.registerUser = async (userData) => {
    const user = await User.create(userData);
    const token = generateToken(user._id, user.role);
    return { user, token };
};

exports.loginUser = async (email, password) => {
    const user = await User.findOne({ email });
    if (!user || !(await user.comparePassword(password))) {
        throw new Error('Invalid email or password');
    }
    const token = generateToken(user._id, user.role);
    return { user, token };
};