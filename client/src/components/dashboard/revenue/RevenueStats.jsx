import { TrendingUp } from "lucide-react";

const RevenueStats = () => {
    return (
        <div className="mb-8 flex items-center justify-between">

            <div>

                <p className="text-secondary">
                    Total Revenue
                </p>

                <h2 className="mt-2 text-4xl font-bold text-text">
                    ₹12.8L
                </h2>

            </div>

            <div className="flex items-center gap-2 rounded-xl bg-green-500/10 px-4 py-2">

                <TrendingUp
                    className="text-green-500"
                    size={18}
                />

                <span className="font-semibold text-green-500">
                    +24.6%
                </span>

            </div>

        </div>
    );
};

export default RevenueStats;