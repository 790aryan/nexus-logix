const Spinner = ({ size = 18 }) => {
    return (
        <div
            className="animate-spin rounded-full border-2 border-white border-t-transparent"
            style={{
                width: size,
                height: size,
            }}
        />
    );
};

export default Spinner;