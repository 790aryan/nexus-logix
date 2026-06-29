const mongoose = require('mongoose');
const bcrypt = require('bcrypt');

const userSchema = new mongoose.Schema({
    name: { type: String, required: true },
    email: { type: String, required: true, unique: true, index: true },
    password: { type: String, required: true },
    role: { type: String, enum: ['ADMIN', 'MANAGER', 'EMPLOYEE'], default: 'EMPLOYEE' },
    phone: String,
    avatar: String,
    isActive: { type: Boolean, default: true },
    lastLogin: Date
}, { timestamps: true });

// Hash password before saving
// Hash password before saving
userSchema.pre('save', async function(save) {
    // Only hash the password if it has been modified (or is new)
    if (!this.isModified('password')) return;
    
    // We don't need 'next' here if the function is async
    this.password = await bcrypt.hash(this.password, 10);
});

userSchema.methods.comparePassword = async function(candidatePassword) {
    return await bcrypt.compare(candidatePassword, this.password);
};

module.exports = mongoose.model('User', userSchema);