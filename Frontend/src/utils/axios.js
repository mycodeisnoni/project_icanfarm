// import axios from "axios";

// const request = axios.create({
//     baseURL : "http://localhost:8080"
// });

// export const api = {
    
// }

import axios from "axios";

const request = axios.create({
    baseURL: "https://jsonplaceholder.typicode.com"
});

export const api = {
    jsonplaceholder: {
        findAll: () => request.get("/"),
        findOne: (id) => request.get(``)
    }
}