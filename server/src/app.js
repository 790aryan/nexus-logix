const express = require('express');
const helmet = require('helmet');
const cors = require('cors');
const morgan = require('morgan');

const app = express();

// Security & Middleware
app.use(helmet());
app.use(cors({ origin: process.env.CLIENT_URL }));
app.use(morgan('dev'));
app.use(express.json());

// Base Route
app.get('/api/v1/health', (req, res) => res.status(200).json({ success: true, message: 'NexusLogix API is running' }));

// 404 Handler
app.use((req, res) => res.status(404).json({ success: false, message: 'Route not found' }));

// Global Error Handler
app.use((err, req, res, next) => {
    console.error(err.stack);
    res.status(500).json({ success: false, message: 'Internal Server Error' });
});

module.exports = app;