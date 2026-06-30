const jwt = require("jsonwebtoken");
const AppError = require("../errors/AppError");

const authMiddleware = (req, res, next) => {
    try {
        // Get token from HttpOnly cookie
        const token = req.cookies.token;

        if (!token) {
            return next(
                new AppError("Authentication required. Please login.", 401)
            );
        }

        // Verify JWT
        const decoded = jwt.verify(token, process.env.JWT_SECRET);

        // Attach user info to request
        req.user = {
            id: decoded.id,
            role: decoded.role,
        };

        next();
    } catch (error) {
        return next(
            new AppError("Invalid or expired token.", 401)
        );
    }
};

module.exports = authMiddleware;