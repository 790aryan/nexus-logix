const jwt = require('jsonwebtoken');
const AppError = require('../errors/AppError');

const authMiddleware = (req, res, next) => {
    const token = req.cookies.token;
    if (!token) return next(new AppError('Unauthorized', 401));

    try {
        const decoded = jwt.verify(token, process.env.JWT_SECRET);
        req.user = decoded;
        next();
    } catch (err) {
        next(new AppError('Invalid token', 401));
    }
};
module.exports = authMiddleware;