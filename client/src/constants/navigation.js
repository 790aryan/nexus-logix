import {
    LayoutDashboard,
    Warehouse,
    Package,
    ShoppingCart,
    Truck,
    BarChart3,
    BrainCircuit,
    Users,
    Settings,
} from "lucide-react";

export const dashboardNavigation = [
    {
        title: "Dashboard",
        path: "/dashboard",
        icon: LayoutDashboard,
    },
    {
        title: "Warehouses",
        path: "/warehouses",
        icon: Warehouse,
    },
    {
        title: "Inventory",
        path: "/inventory",
        icon: Package,
    },
    {
        title: "Orders",
        path: "/orders",
        icon: ShoppingCart,
    },
    {
        title: "Logistics",
        path: "/logistics",
        icon: Truck,
    },
    {
        title: "Analytics",
        path: "/analytics",
        icon: BarChart3,
    },
    {
        title: "AI Insights",
        path: "/ai-insights",
        icon: BrainCircuit,
    },
    {
        title: "Employees",
        path: "/employees",
        icon: Users,
    },
    {
        title: "Settings",
        path: "/settings",
        icon: Settings,
    },
];