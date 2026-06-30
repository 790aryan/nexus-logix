const Card = ({ children, className = "" }) => {
    return (
        <div
            className={`
                bg-[#5B6076]
                rounded-2xl
                shadow-2xl
                p-8
                border
                border-[#6A6F83]
                ${className}
            `}
        >
            {children}
        </div>
    );
};

export default Card;