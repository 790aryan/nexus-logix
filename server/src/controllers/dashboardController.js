const asyncHandler = require('../helpers/asyncHandler');
const { successResponse } = require('../helpers/apiResponse');

exports.getDashboardStats = asyncHandler(async (req, res) => {
    try {
        console.log("Fetching dashboard stats for user:", req.user);
        
        // Mock data
        const data = {
            stats: { warehouses: 12, products: 150, orders: 45, employees: 8 },
            recentOrders: [
                { id: 'ORD-001', customer: 'Acme Corp', status: 'Pending', total: 1200 },
                { id: 'ORD-002', customer: 'Globex', status: 'Completed', total: 850 }
            ]
        };
        
        successResponse(res, 'Dashboard data fetched', data);
    } catch (error) {
        console.error("DASHBOARD_CONTROLLER_ERROR:", error);
        throw error; // This passes it to our global errorHandler
    }
});