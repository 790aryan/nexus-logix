import { motion } from "framer-motion";
import { Mail, LockKeyhole, User, UserPlus } from "lucide-react";
import { Link, useNavigate } from "react-router-dom";
import { useForm } from "react-hook-form";
import { zodResolver } from "@hookform/resolvers/zod";

import { registerSchema } from "../../schemas/auth.schema";
import useAuthStore from "../../store/authStore";

import { Button, Card, Input } from "../ui";
import { FormField } from "../forms";

const RegisterForm = () => {
    const navigate = useNavigate();

    const {
        register: registerUser,
        isLoading,
        error,
        clearError,
    } = useAuthStore();

    const {
        register,
        handleSubmit,
        formState: { errors },
    } = useForm({
        resolver: zodResolver(registerSchema),

        defaultValues: {
            name: "",
            email: "",
            password: "",
            confirmPassword: "",
        },
    });

    const onSubmit = async (data) => {
        try {
            clearError();

            await registerUser({
                name: data.name,
                email: data.email,
                password: data.password,
            });

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
                        Create Account
                    </h2>

                    <p className="mt-2 text-secondary">
                        Join OptiFlow and start managing smarter.
                    </p>

                </div>

                <form
                    onSubmit={handleSubmit(onSubmit)}
                    className="space-y-6"
                >

                    <FormField
                        label="Full Name"
                        required
                        error={errors.name}
                    >
                        <Input
                            icon={User}
                            name="name"
                            register={register}
                            placeholder="Enter your full name"
                        />
                    </FormField>

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
                            placeholder="Create a password"
                        />
                    </FormField>

                    <FormField
                        label="Confirm Password"
                        required
                        error={errors.confirmPassword}
                    >
                        <Input
                            type="password"
                            icon={LockKeyhole}
                            name="confirmPassword"
                            register={register}
                            placeholder="Confirm your password"
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

                    <Button
                        type="submit"
                        loading={isLoading}
                        className="mt-2"
                    >
                        <div className="flex items-center justify-center gap-2">

                            <UserPlus size={18} />

                            <span>
                                {isLoading
                                    ? "Creating Account..."
                                    : "Create Account"}
                            </span>

                        </div>
                    </Button>

                </form>

                <div className="mt-8 border-t border-border pt-6 text-center">

                    <p className="text-secondary">

                        Already have an account?

                        <Link
                            to="/login"
                            className="ml-2 font-semibold text-primary transition hover:text-primary-hover"
                        >
                            Login
                        </Link>

                    </p>

                </div>

            </Card>

        </motion.div>
    );
};

export default RegisterForm;