import { motion } from "framer-motion";
import { Logo } from "../components/ui";

const AuthLayout = ({ children }) => {
    return (
        <div className="min-h-screen bg-background flex items-center justify-center px-4 py-10">

            {/* Background Glow */}
            <div className="absolute inset-0 overflow-hidden pointer-events-none">

                <div className="absolute top-0 left-0 h-96 w-96 rounded-full bg-primary/20 blur-3xl" />

                <div className="absolute bottom-0 right-0 h-96 w-96 rounded-full bg-accent/20 blur-3xl" />

            </div>

            <motion.div
                initial={{ opacity: 0, y: 40 }}
                animate={{ opacity: 1, y: 0 }}
                transition={{
                    duration: 0.5,
                    ease: "easeOut",
                }}
                className="relative z-10 w-full max-w-md"
            >

                <div className="mb-8 flex justify-center">

                    <Logo />

                </div>

                {children}

            </motion.div>

        </div>
    );
};

export default AuthLayout;