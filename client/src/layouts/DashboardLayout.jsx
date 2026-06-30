import Sidebar from "../components/dashboard/Sidebar";
import TopNavbar from "../components/dashboard/TopNavbar";

const DashboardLayout = ({ children }) => {
    return (
        <div className="flex min-h-screen bg-background">

            <Sidebar />

            <div className="flex flex-1 flex-col">

                <div className="p-8">

                    <TopNavbar />

                    {children}

                </div>

            </div>

        </div>
    );
};

export default DashboardLayout;