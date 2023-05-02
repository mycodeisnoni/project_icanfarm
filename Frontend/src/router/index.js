import Vue from 'vue'
import VueRouter from 'vue-router'
import LoginView from "../views/LoginView.vue"
import MonitorView from "../views/MonitorView.vue"
import RPiView from "../views/RPiView.vue"
import AccountView from "../views/AccountView.vue"
import HubView from "../views/HubView.vue"

Vue.use(VueRouter)

const routes = [
  {
    path: "/login",
    name: "Login",
    component: LoginView,
  },
  {
    path: "/monitor",
    name: "Monitor",
    component: MonitorView,
  },
  {
    path: "/monitor/:id",
    name: "Monitor_hub",
    component: HubView,
  },
  {
    path: "/rpi",
    name: "RPi",
    component: RPiView,
  },
  {
    path: "/account",
    name: "Account",
    component: AccountView,
  },
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
