require("dotenv").config();

const mongoose = require("mongoose");
const authService = require("./src/services/authService");

async function test() {
    try {
        await mongoose.connect(process.env.MONGO_URI);

        const result = await authService.loginUser({
            email: "aryan@test.com",
            password: "123456",
        });

        console.log(result);

        await mongoose.disconnect();
    } catch (err) {
        console.error(err.message);
    }
}

test();