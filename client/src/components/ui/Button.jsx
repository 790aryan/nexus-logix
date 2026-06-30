import Spinner from "./Spinner";

const Button = ({
    children,
    type = "button",
    loading = false,
    disabled = false,
    className = "",
}) => {
    return (
        <button
            type={type}
            disabled={loading || disabled}
            className={`
                flex
                w-full
                items-center
                justify-center
                gap-2
                rounded-xl
                bg-[#8458B3]
                px-6
                py-3
                font-semibold
                text-white
                transition-all
                duration-300

                hover:bg-[#7344AA]
                hover:shadow-xl

                active:scale-95

                disabled:cursor-not-allowed
                disabled:opacity-60

                ${className}
            `}
        >
            {loading && <Spinner />}

            {children}
        </button>
    );
};

export default Button;