import {
    Warehouse,
    Package,
    ShoppingCart,
    IndianRupee,
} from "lucide-react";

import KPICard from "./KPICard";

const KPISection = () => {

    const cards = [
        {
            title: "Warehouses",
            value: "12",
            trend: "+12%",
            trendLabel: "vs last month",
            icon: Warehouse,
        },
        {
            title: "Inventory",
            value: "8,240",
            trend: "+18%",
            trendLabel: "stock growth",
            icon: Package,
        },
        {
            title: "Orders",
            value: "148",
            trend: "+9%",
            trendLabel: "today",
            icon: ShoppingCart,
        },
        {
            title: "Revenue",
            value: "₹12.8L",
            trend: "+24%",
            trendLabel: "this month",
            icon: IndianRupee,
        },
    ];

    return (
        <div className="grid grid-cols-1 gap-6 md:grid-cols-2 xl:grid-cols-4">

            {cards.map((card) => (

                <KPICard
                    key={card.title}
                    {...card}
                />

            ))}

        </div>
    );
};

export default KPISection;