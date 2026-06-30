import DashboardLayout from "../../layouts/DashboardLayout";
import KPISection from "../../components/dashboard/KPISection";

const DashboardPage = () => {
    return (
        <DashboardLayout>

            <div className="space-y-8">

                <div>

                    <h1 className="text-4xl font-bold text-text">
                        Good Morning 👋
                    </h1>

                    <p className="mt-2 text-secondary">
                        Here's what's happening across your warehouses today.
                    </p>

                </div>

                <KPISection />

            </div>

        </DashboardLayout>
    );
};

export default DashboardPage;