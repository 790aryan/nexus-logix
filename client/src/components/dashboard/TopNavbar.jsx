import { Search, Bell, ChevronDown } from "lucide-react";
import { motion } from "framer-motion";
import useAuthStore from "../../store/authStore";

const TopNavbar = () => {
    const user = useAuthStore((state) => state.user);

    return (
        <header className="mb-8 flex items-center justify-between">

            {/* Search */}

            <div className="relative w-full max-w-md">

                <Search
                    size={18}
                    className="absolute left-4 top-1/2 -translate-y-1/2 text-secondary"
                />

                <input
                    type="text"
                    placeholder="Search products, orders, warehouses..."
                    className="w-full rounded-xl border border-border bg-surface py-3 pl-12 pr-4 text-text outline-none transition focus:border-primary"
                />

            </div>

            {/* Right Side */}

            <div className="ml-6 flex items-center gap-5">

                <motion.button
                    whileHover={{ scale: 1.05 }}
                    whileTap={{ scale: 0.95 }}
                    className="rounded-xl bg-surface p-3"
                >
                    <Bell className="text-text" size={20} />
                </motion.button>

                <motion.div
                    whileHover={{ scale: 1.02 }}
                    className="flex cursor-pointer items-center gap-3 rounded-xl bg-surface px-4 py-2"
                >
                    <div className="flex h-10 w-10 items-center justify-center rounded-full bg-primary text-white font-bold">
                        {user?.name?.charAt(0).toUpperCase() || "U"}
                    </div>

                    <div>

                        <p className="font-semibold text-text">
                            {user?.name || "User"}
                        </p>

                        <p className="text-xs text-secondary">
                            {user?.role}
                        </p>

                    </div>

                    <ChevronDown
                        size={18}
                        className="text-secondary"
                    />

                </motion.div>

            </div>

        </header>
    );
};

export default TopNavbar;