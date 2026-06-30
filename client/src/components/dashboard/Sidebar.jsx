import { motion } from "framer-motion";
import { NavLink } from "react-router-dom";
import { LogOut } from "lucide-react";

import { Logo } from "../ui";
import { dashboardNavigation } from "../../constants/navigation";
import useAuthStore from "../../store/authStore";

const Sidebar = () => {
    const logout = useAuthStore((state) => state.logout);

    const handleLogout = async () => {
        await logout();
    };

    return (
        <aside className="flex h-screen w-72 flex-col border-r border-border bg-surface">

            {/* Logo */}

            <div className="border-b border-border p-6">

                <Logo />

            </div>

            {/* Navigation */}

            <nav className="flex-1 px-4 py-6">

                <div className="space-y-2">

                    {dashboardNavigation.map((item) => {

                        const Icon = item.icon;

                        return (
                            <NavLink
                                key={item.path}
                                to={item.path}
                                className={({ isActive }) =>
                                    `flex items-center gap-3 rounded-xl px-4 py-3 text-sm font-medium transition-all duration-300 ${
                                        isActive
                                            ? "bg-primary text-white shadow-lg"
                                            : "text-secondary hover:bg-background hover:text-text"
                                    }`
                                }
                            >
                                <Icon size={20} />

                                <span>
                                    {item.title}
                                </span>

                            </NavLink>
                        );

                    })}

                </div>

            </nav>

            {/* Footer */}

            <div className="border-t border-border p-4">

                <motion.button
                    whileHover={{
                        scale: 1.02,
                    }}
                    whileTap={{
                        scale: 0.98,
                    }}
                    onClick={handleLogout}
                    className="flex w-full items-center gap-3 rounded-xl px-4 py-3 text-secondary transition hover:bg-background hover:text-danger"
                >
                    <LogOut size={20} />

                    <span>
                        Logout
                    </span>

                </motion.button>

            </div>

        </aside>
    );
};

export default Sidebar;