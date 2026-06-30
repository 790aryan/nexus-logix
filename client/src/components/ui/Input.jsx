import { Eye, EyeOff } from "lucide-react";
import { useState } from "react";
import { cn } from "../../utils/cn";

const Input = ({
    type = "text",
    placeholder = "",
    register,
    name,
    icon: Icon,
    disabled = false,
    className = "",
}) => {
    const [showPassword, setShowPassword] = useState(false);

    const inputType =
        type === "password"
            ? showPassword
                ? "text"
                : "password"
            : type;

    return (
        <div
            className={cn(
                "flex items-center rounded-xl border border-border bg-background px-4 transition-all duration-300",
                "focus-within:border-primary focus-within:ring-2 focus-within:ring-primary",
                disabled && "cursor-not-allowed opacity-60",
                className
            )}
        >
            {Icon && (
                <Icon
                    size={20}
                    className="mr-3 text-secondary"
                />
            )}

            <input
                type={inputType}
                placeholder={placeholder}
                disabled={disabled}
                {...(register && register(name))}
                className="flex-1 bg-transparent py-3 text-text placeholder:text-secondary outline-none"
            />

            {type === "password" && (
                <button
                    type="button"
                    onClick={() =>
                        setShowPassword((prev) => !prev)
                    }
                    className="text-secondary transition hover:text-text"
                >
                    {showPassword ? (
                        <EyeOff size={20} />
                    ) : (
                        <Eye size={20} />
                    )}
                </button>
            )}
        </div>
    );
};

export default Input;