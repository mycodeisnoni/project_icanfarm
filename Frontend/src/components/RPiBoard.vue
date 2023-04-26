.<template>
  <div class="container">
    <div class="item1">
      <div class="nav1">
        <div class="ICON"></div>
        <div>User Name</div>
        <div class="dropdown">
          <button class="btn btn-secondary dropdown-toggle" type="button" data-bs-toggle="dropdown" aria-expanded="false">허브명</button>
          <ul class="dropdown-menu">
            <li><a class="dropdown-item" href="#">Action</a></li>
            <li><a class="dropdown-item" href="#">Another action</a></li>
            <li><a class="dropdown-item" href="#">Something else here</a></li>
          </ul>
        </div>
      </div>
      <div class="nav2">
        <div>
          <router-link to="/monitor" style="text-decoration: none; color: black;">Monitor</router-link>
        </div>
        <div>
          <router-link to="/" style="text-decoration: none; color: black;">LOGOUT</router-link>
        </div>
      </div>
      <router-view/>
    </div>

    <div class="item2">
      <div class="PW_box">
        <h3>RPi Password</h3>
        <input type="text">
        <button>저장</button>
      </div>
    </div>
  </div>
</template>

<script>
export default {

}
</script>

<style scoped>
.item1{
  display: flex;
  justify-content: space-between;
  background-color: rgb(169, 201, 202);
  height: 20%;
  
}
.nav1{
  display: flex;
  align-items: center;
}
.nav2{
  display: flex;
  align-items: center;

  color: white;
}
.ICON{
  background-image: url("../assets/ICON_ICANFARM.png");
  background-size: cover;
  width: 81px;
  height: 91px;
  Top: 40%;
  Left: 32px;
}
.item2{
  display: flex;
  background-color: rgb(45, 51, 51);
}
.PW_box{
  background-color: rgb(217, 217, 217);
  width: 500px;
  height: 300px;
  border-radius: 50px;
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
}
</style>