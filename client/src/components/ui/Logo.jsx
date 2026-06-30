import { Boxes } from "lucide-react";

const Logo = () => {
    return (
        <div className="flex items-center justify-center gap-3">

            <div className="rounded-xl bg-[#8458B3] p-3 shadow-lg">
                <Boxes
                    size={28}
                    className="text-white"
                />
            </div>

            <div>

                <h1 className="text-3xl font-bold text-[#E5EAF5]">
                    OptiFlow
                </h1>

                <p className="text-sm text-[#A0D2EB]">
                    Smart Warehouse Platform
                </p>

            </div>

        </div>
    );
};

export default Logo;