let EL = document.getElementById("#room");

class Room {
    constructor(number, descr, descrshort) {
        this.number = number;
        this.descr = descr;
        this.descrshort = descrshort;
        this.#visited = false;
    }

    // Get connections
    connect(connections) {
        this.connections = connections;
    }

    // Add item to room
    addItems(item) {
        if (!this.items) {
            this.items = Array();
        }
        this.items.push(item); 
    }

    // If room visited, present description to DOM
    visit() {
        if (this.#visited) {
            EL.innerHTML = this.descrshort;
        } else {
            this.#vistied = true;
            EL.innerHTML = this.descr;
        }
    }
}