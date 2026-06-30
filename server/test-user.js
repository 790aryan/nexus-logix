require("dotenv").config();

const mongoose = require("mongoose");
const User = require("./src/models/User");

async function test() {
    try {
        await mongoose.connect(process.env.MONGO_URI);

        const user = await User.create({
            name: "Aryan",
            email: "aryan@test.com",
            password: "123456"
        });

        console.log(user);

        await mongoose.disconnect();
    } catch (err) {
        console.error(err);
    }
}

test();