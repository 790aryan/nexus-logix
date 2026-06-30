const express = require('express');
const helmet = require('helmet');
const cors = require('cors');
const morgan = require('morgan');
const cookieParser = require('cookie-parser');

// Import Middlewares and Routes
const authRoutes = require('./routes/auth.routes');
const dashboardRoutes = require('./routes/dashboard.routes'); // ADD THIS
const errorHandler = require('./middleware/errorHandler');
const notFound = require('./middleware/notFound');

const app = express();

// Security & Middleware
app.use(helmet());
app.use(cors({ 
    origin: 'http://localhost:5173', // Hardcode this temporarily
    credentials: true
}));
app.use(morgan('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(cookieParser());

// Base API Routes
app.get('/api/v1/health', (req, res) => res.status(200).json({ success: true, message: 'NexusLogix API is running' }));
app.use('/api/v1/auth', authRoutes);
app.use('/api/v1/dashboard', dashboardRoutes); // ADD THIS

// 404 Handler
app.use(notFound);

// Global Error Handler
app.use(errorHandler);

module.exports = app;