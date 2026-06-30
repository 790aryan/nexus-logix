const AppError = require("../errors/AppError");

const errorHandler = (err, req, res, next) => {
    let error = err;

    if (!(error instanceof AppError)) {
        error = new AppError(
            "Internal Server Error",
            500
        );

        console.error(err);
    }

    const response = {
        success: false,
        status: error.status,
        message: error.message,
    };

    // Only expose stack if explicitly requested
    if (
        process.env.NODE_ENV === "development" &&
        process.env.SHOW_STACK === "true"
    ) {
        response.stack = err.stack;
    }

    res.status(error.statusCode).json(response);
};

module.exports = errorHandler;