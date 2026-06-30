const RevenueHeader = () => {
    return (
        <div className="mb-8 flex items-center justify-between">

            <div>

                <h2 className="text-2xl font-bold text-text">
                    Revenue Analytics
                </h2>

                <p className="mt-1 text-secondary">
                    Monthly revenue performance
                </p>

            </div>

            <div className="rounded-xl border border-border bg-background px-4 py-2">

                <span className="text-sm text-secondary">
                    This Year
                </span>

            </div>

        </div>
    );
};

export default RevenueHeader;