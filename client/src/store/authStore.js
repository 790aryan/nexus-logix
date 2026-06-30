import { create } from "zustand";
import authService from "../services/authService";
import { toast } from "sonner";

const useAuthStore = create((set, get) => ({
    // =========================
    // State
    // =========================
    user: null,
    isAuthenticated: false,
    isLoading: false,
    isCheckingAuth: true,
    error: null,

    // =========================
    // Register
    // =========================
    register: async (userData) => {
        try {
            set({
                isLoading: true,
                error: null,
            });

            const response = await authService.register(userData);
            toast.success("Account created successfully!");
            set({
                user: response.data.user,
                isAuthenticated: true,
                isLoading: false,
                isCheckingAuth: false,
                error: null,
            });

            return response;
        } catch (error) {
            const message =
                error.response?.data?.message ||
                "Registration failed";

            set({
                error: message,
                isLoading: false,
            });

            toast.error(message);
            throw error;
        }
    },

    // =========================
    // Login
    // =========================
    login: async (credentials) => {
        try {
            set({
                isLoading: true,
                error: null,
            });

            const response = await authService.login(credentials);
            toast.success("Welcome back!");
            set({
                user: response.data.user,
                isAuthenticated: true,
                isLoading: false,
                isCheckingAuth: false,
                error: null,
            });

            return response;
        } catch (error) {
            const message =
                error.response?.data?.message ||
                "Login failed";

            set({
                error: message,
                isLoading: false,
            });

            toast.error(message);
            throw error;
        }
    },

    // =========================
    // Logout
    // =========================
logout: async () => {
    try {
        set({
            isLoading: true,
        });

        await authService.logout();

        toast.success("Logged out successfully");

        set({
            user: null,
            isAuthenticated: false,
            isLoading: false,
            isCheckingAuth: false,
            error: null,
        });
    } catch (error) {
        set({
            isLoading: false,
        });

        console.error(error);
    }
},

    // =========================
    // Restore Session
    // =========================
    checkAuth: async () => {
        set({
            isCheckingAuth: true,
        });
        try {
            set({
                isLoading: true,
            });

            const response = await authService.getCurrentUser();

           set({
                user: response.data.user,
                isAuthenticated: true,
                isLoading: false,
                isCheckingAuth: false,
                error: null,
            });
        } catch  {
            set({
                user: null,
                isAuthenticated: false,
                isLoading: false,
                isCheckingAuth: false,
            });
        }
    },

    // =========================
    // Clear Error
    // =========================
    clearError: () => {
        set({
            error: null,
        });
    },
}));

export default useAuthStore;