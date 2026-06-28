# Database Schema Design – NexusLogix

## Overview
This document outlines the schema design and entity relationships for the NexusLogix platform. We utilize a document-based NoSQL approach (MongoDB) optimized for high-read performance and scalability.

---

## 1. ER Diagram Summary
- **Users** manage **Warehouses**.
- **Warehouses** store **Products**.
- **Warehouses** fulfill **Orders**.
- **Orders** contain a collection of **Products**.

---

## 2. Collections & Schema Definitions

### Users
*Stores platform users (Admin, Manager, Employee).*
- `_id`: ObjectID (Primary)
- `name`: String (Required)
- `email`: String (Required, Unique, Indexed)
- `password`: String (Required, Hashed)
- `role`: String (Enum: ADMIN, MANAGER, EMPLOYEE)
- `phone`: String
- `isActive`: Boolean (Default: true)
- `createdAt/updatedAt`: Timestamps

### Warehouses
*Physical storage locations.*
- `warehouseName`: String (Required)
- `warehouseCode`: String (Required, Unique, Indexed)
- `manager`: ObjectID (Reference: Users)
- `address/city/state/country`: Strings
- `latitude/longitude`: Number (For future Geolocation/Optimization)
- `capacity`: Number (Max capacity)
- `currentInventory`: Number
- `isActive`: Boolean

### Products
*Inventory items stored within warehouses.*
- `productName`: String (Required)
- `sku`: String (Required, Unique, Indexed)
- `category`: String
- `price`: Number
- `weight/dimensions`: Number
- `warehouseId`: ObjectID (Reference: Warehouses)
- `shelfNumber`: String
- `minimumStock`: Number (For low-stock alerts)
- `quantity`: Number

### Orders
*Customer transaction records.*
- `orderNumber`: String (Unique, Indexed)
- `customerName`: String
- `warehouseId`: ObjectID (Reference: Warehouses)
- `products`: Array<{productId: ObjectID, quantity: Number}>
- `status`: String (Enum: Pending, Packed, Out for Delivery, Delivered, Cancelled)
- `totalAmount`: Number
- `createdAt`: Timestamp

---

## 3. Design Principles
- **Normalization:** Foreign key references (e.g., `warehouseId`) are used to ensure data integrity across collections.
- **Indexing:** All unique identifiers (`sku`, `warehouseCode`, `orderNumber`) and lookup fields (`email`) are indexed for $O(\log N)$ search performance.
- **Soft Deletion:** We use `isActive` flags instead of physical deletion to maintain historical audit trails.
- **Future-Proofing:** Geolocation and dimension fields are included to facilitate Phase 4 (Optimization Engine) without breaking changes.