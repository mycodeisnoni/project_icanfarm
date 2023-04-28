.<template>
  <div>
    <div class="item1">
      <div class="nav1">
        <div class="ICON"></div>
        <div style="font-size: 24px;">User Name</div>
        <div class="dropdown">
          <button class="btn btn-secondary dropdown-toggle" type="button" data-bs-toggle="dropdown" aria-expanded="false">허브명</button>
          <ul class="dropdown-menu">
            <li><a class="dropdown-item" href="#">Hub No. 1</a></li>
            <li><a class="dropdown-item" href="#">Hub No. 2</a></li>
            <li><a class="dropdown-item" href="#">Hub No. 3</a></li>
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
  </div>
</template>

<script>
export default {

}
</script>

<style scoped>
.item1{
  background-color: rgb(169, 201, 202);
  position: absolute;
  width: 100%;
  height: 10%;
  top: 0;
  left: 0;
}
.item1 > *{
  margin: 0px 10px;
}
.item1 > * > div{
  margin: 0px 7px;
}
.nav1{
  display: flex;
  align-items: center;
  margin-right: auto;
}
.ICON{
  background-image: url("../assets/ICON_ICANFARM.png");
  background-size: cover;
  width: 81px;
  height: 91px;
  Top: 35px;
  Left: 32px;
}
</style>