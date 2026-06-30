import { motion } from "framer-motion";
import { TrendingUp } from "lucide-react";

const KPICard = ({
    title,
    value,
    icon: Icon,
    trend,
    trendLabel,
}) => {
    return (
        <motion.div
            whileHover={{
                y: -6,
                scale: 1.02,
            }}
            transition={{
                duration: 0.2,
            }}
            className="rounded-2xl border border-border bg-surface p-6 shadow-lg"
        >
            <div className="flex items-center justify-between">

                <div>

                    <p className="text-sm font-medium text-secondary">
                        {title}
                    </p>

                    <h2 className="mt-3 text-4xl font-bold text-text">
                        {value}
                    </h2>

                </div>

                <div className="rounded-xl bg-primary/20 p-4">

                    <Icon
                        size={28}
                        className="text-primary"
                    />

                </div>

            </div>

            <div className="mt-6 flex items-center gap-2">

                <TrendingUp
                    size={18}
                    className="text-green-500"
                />

                <span className="font-semibold text-green-500">
                    {trend}
                </span>

                <span className="text-secondary">
                    {trendLabel}
                </span>

            </div>

        </motion.div>
    );
};

export default KPICard;