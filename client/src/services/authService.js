import api from "../lib/api";

/**
 * Register a new user
 */
export const register = async (userData) => {
    const response = await api.post("/auth/register", userData);
    return response.data;
};

/**
 * Login user
 */
export const login = async (credentials) => {
    const response = await api.post("/auth/login", credentials);
    return response.data;
};

/**
 * Logout user
 */
export const logout = async () => {
    const response = await api.post("/auth/logout");
    return response.data;
};

/**
 * Get currently logged in user
 */
export const getCurrentUser = async () => {
    const response = await api.get("/auth/me");
    return response.data;
};

const authService = {
    register,
    login,
    logout,
    getCurrentUser,
};

export default authService;