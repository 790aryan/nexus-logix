import { Navigate } from "react-router-dom";
import useAuthStore from "../store/authStore";

const ProtectedRoute = ({ children }) => {
    const {
        user,
        isCheckingAuth,
    } = useAuthStore();

    if (isCheckingAuth) {
        return (
            <div className="flex min-h-screen items-center justify-center bg-background">
                <h2 className="text-xl font-semibold text-text">
                    Checking authentication...
                </h2>
            </div>
        );
    }

    if (!user) {
        return <Navigate to="/login" replace />;
    }

    return children;
};

export default ProtectedRoute;