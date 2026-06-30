import { motion } from "framer-motion";
import { Mail, LockKeyhole, LogIn } from "lucide-react";
import { Link, useNavigate } from "react-router-dom";
import { useForm } from "react-hook-form";
import { zodResolver } from "@hookform/resolvers/zod";

import { loginSchema } from "../../schemas/auth.schema";
import useAuthStore from "../../store/authStore";

import { Button, Card, Input } from "../ui";
import { FormField } from "../forms";

const LoginForm = () => {
    const navigate = useNavigate();

    const {
        login,
        isLoading,
        error,
        clearError,
    } = useAuthStore();

    const {
        register,
        handleSubmit,
        formState: { errors },
    } = useForm({
        resolver: zodResolver(loginSchema),

        defaultValues: {
            email: "",
            password: "",
        },
    });

    const onSubmit = async (data) => {
        try {
            clearError();

            await login(data);

            navigate("/dashboard");
        } catch (err) {
            console.error(err);
        }
    };

    return (
        <motion.div
            initial={{
                opacity: 0,
                y: 25,
            }}
            animate={{
                opacity: 1,
                y: 0,
            }}
            transition={{
                duration: 0.45,
            }}
        >
            <Card>

                <div className="mb-8 text-center">

                    <h2 className="text-3xl font-bold text-text">
                        Welcome Back
                    </h2>

                    <p className="mt-2 text-secondary">
                        Sign in to continue managing your warehouse.
                    </p>

                </div>

                <form
                    onSubmit={handleSubmit(onSubmit)}
                    className="space-y-6"
                >

                    <FormField
                        label="Email Address"
                        required
                        error={errors.email}
                    >

                        <Input
                            icon={Mail}
                            name="email"
                            register={register}
                            placeholder="Enter your email"
                        />

                    </FormField>

                    <FormField
                        label="Password"
                        required
                        error={errors.password}
                    >

                        <Input
                            type="password"
                            icon={LockKeyhole}
                            name="password"
                            register={register}
                            placeholder="Enter your password"
                        />

                    </FormField>
                    {error && (
                        <motion.div
                            initial={{ opacity: 0 }}
                            animate={{ opacity: 1 }}
                            className="rounded-xl border border-danger/30 bg-danger/10 p-3"
                        >
                            <p className="text-sm text-danger">
                                {error}
                            </p>
                        </motion.div>
                    )}

                    <div className="flex items-center justify-between text-sm">

                        <label className="flex items-center gap-2 text-secondary">

                            <input
                                type="checkbox"
                                className="h-4 w-4 accent-primary"
                            />

                            Remember Me

                        </label>

                        <button
                            type="button"
                            className="font-medium text-accent transition hover:text-primary"
                        >
                            Forgot Password?
                        </button>

                    </div>

                    <Button
                        type="submit"
                        loading={isLoading}
                        className="mt-2"
                    >
                        <div className="flex items-center justify-center gap-2">

                            <LogIn size={18} />

                            <span>
                                {isLoading ? "Signing In..." : "Login"}
                            </span>

                        </div>
                    </Button>

                </form>

                <div className="mt-8 border-t border-border pt-6 text-center">

                    <p className="text-secondary">

                        Don't have an account?

                        <Link
                            to="/register"
                            className="ml-2 font-semibold text-primary transition hover:text-primary-hover"
                        >
                            Create Account
                        </Link>

                    </p>

                </div>

            </Card>

        </motion.div>
    );
};

export default LoginForm;