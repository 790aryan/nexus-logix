const authService = require('../services/authService');
const asyncHandler = require('../helpers/asyncHandler');
const { successResponse } = require('../helpers/apiResponse');

exports.register = asyncHandler(async (req, res) => {
    const { user, token } = await authService.registerUser(req.body);
    res.cookie('token', token, { httpOnly: true, secure: process.env.NODE_ENV === 'production' });
    successResponse(res, 'User registered successfully', { user }, 201);
});

exports.login = asyncHandler(async (req, res) => {
    const { user, token } = await authService.loginUser(req.body.email, req.body.password);
    res.cookie('token', token, { httpOnly: true, secure: process.env.NODE_ENV === 'production' });
    successResponse(res, 'Login successful', { user });
});

exports.logout = (req, res) => {
    res.clearCookie('token');
    successResponse(res, 'Logged out successfully');
};