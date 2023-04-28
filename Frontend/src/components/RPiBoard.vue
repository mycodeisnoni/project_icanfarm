.<template>
  <div class="container">
    <div class="item1">
      <div class="nav1">
        <div class="ICON"></div>
        <div style="font-size: 24px;">User Name</div>
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
        <!-- <div></div> -->
        <label for="" style="font-size: 48px; font-weight: bold;">RPi Password</label>
        <input type="text" style="font-size: 64px; text-align: center;" v-model="inputValue" @input="onInput" maxlength="6" size="6" placeholder="000000">
        <button type="button" style="font-size: 24px; height: 50px; width: 100px;" :disabled="inputValue.length !== 6" @click="openModal">SAVE</button>
      </div>
    </div>

    <div class="modal" v-if="isModalOpen">
      <div class="modal-content">
        <span class="close" @click="closeModal">&times;</span>
        <p>Modal Content</p>
      </div>
    </div>

  </div>
</template>

<script>
import 'bootstrap/dist/css/bootstrap.css';
import 'bootstrap/dist/js/bootstrap.js';

export default {
  data() {
    return{
      inputValue: '',
      isModalOpen: false,
    }
  },
  mounted() {
    // Dropdown 초기화
    var dropdownElementList = [].slice.call(document.querySelectorAll('.dropdown-toggle'))
    var dropdownList = dropdownElementList.map(function (dropdownToggle) {
      return new bootstrap.Dropdown(dropdownToggle)
    })
  },
  methods: {
    openModal() {
      this.isModalOpen = true;
    },
    closeModal() {
      this.isModalOpen = false;
    },
    onInput(){
      this.inputValue = this.inputValue.replace(/[^0-9]/g, '').substring(0, 6);
    },
  }
}
</script>



<style scoped>
.item1{
  display: flex;
  /* justify-content: space-between; */
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
.nav2{
  display: flex;
  align-items: center;
  color: white;
  margin-left: auto;
}
.ICON{
  background-image: url("../assets/ICON_ICANFARM.png");
  background-size: cover;
  position: relative;
  width: 81px;
  height: 91px;
}
.item2{
  display: flex;
  background-color: rgb(45, 51, 51);
  position: absolute;
  width: 100%;
  height: 90%;
  top: 10%;
  left: 0;
  justify-content: center;
  align-items: center;
}
.PW_box{
  background-color: rgb(217, 217, 217);
  border-radius: 50px;
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  position: relative;
  padding: 10% 20%;
}
.PW_box > *{
  margin: 20px 0;
}
.modal {
  display: block;
  position: fixed;
  z-index: 1;
  left: 0;
  top: 0;
  width: 100%;
  height: 100%;
  background-color: rgba(0, 0, 0, 0.4);
}
.modal-content {
  background-color: white;
  margin: 15% auto;
  padding: 20px;
  border: 1px solid #888;
  width: 80%;
}
</style>