const express = require('express');
const router = express.Router();
const dashboardController = require('../controllers/dashboardController');
const authMiddleware = require('../middleware/authMiddleware');

// Ensure the middleware is passed as a function reference
router.get('/', authMiddleware, dashboardController.getDashboardStats);

module.exports = router;