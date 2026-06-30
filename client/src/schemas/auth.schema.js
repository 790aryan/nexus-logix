import { z } from "zod";

/* ==========================================================
   Login Schema
========================================================== */

export const loginSchema = z.object({
    email: z
        .string()
        .trim()
        .min(1, "Email is required")
        .email("Please enter a valid email"),

    password: z
        .string()
        .min(1, "Password is required")
        .min(6, "Password must be at least 6 characters"),
});

/* ==========================================================
   Register Schema
========================================================== */

export const registerSchema = z
    .object({
        name: z
            .string()
            .trim()
            .min(3, "Name must be at least 3 characters")
            .max(50, "Name cannot exceed 50 characters"),

        email: z
            .string()
            .trim()
            .min(1, "Email is required")
            .email("Please enter a valid email"),

        password: z
            .string()
            .min(6, "Password must be at least 6 characters")
            .max(100, "Password cannot exceed 100 characters"),

        confirmPassword: z
            .string()
            .min(1, "Please confirm your password"),
    })
    .refine(
        (data) => data.password === data.confirmPassword,
        {
            path: ["confirmPassword"],
            message: "Passwords do not match",
        }
    );