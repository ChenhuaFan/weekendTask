# Simple Lottery Management System
This is a weekend task repository for our C program design class, Lottery Management System.

# Function Analysis
We need a simple system that can help people to insert, update, and track lottery.

# Structure Design
We considered the web service design and migrated the same idea to our lottery management system. So we separated the main logic to the user-interface layer, business logic layer, and data persistence layer.
* User-interface layer mainly offers functions that display available options and information the user needs and react to the user's interaction.
* business logic layer mainly offers functions that handle interaction, like insert and update lottery, using APIs of the data persistence layer.
* data persistence layer mainly offers functions that store and read data from local files and generate and maintain the linked list—like IO operations.

