<template>
  <div class="chart-container">
    <donut-chart :data="chartData" :options="chartOptions" />
  </div>
</template>

<script>
import DonutChart from './chart_Doughnut.vue';

export default {
  name: 'App',
  components: {
    DonutChart,
  },
  data() {
    return {
      chartData: {
        labels: ['Red', 'Blue'],
        datasets: [
          {
            label: 'My First Dataset',
            data: [300, 350-300],
            backgroundColor: ['rgb(255, 99, 132)', 'rgb(54, 162, 235)'],
            hoverOffset: 4,
          },
        ],
      },
      chartOptions: {
        responsive: true,
        maintainAspectRatio: false,
      },
    };
  },
  mounted() {
    this.$nextTick(() => {
      if (this.$refs.chart) {
        this.renderChart();
        const canvas = this.$refs.donutChart.$refs.chart;
        canvas.height = canvas.offsetWidth;
        canvas.width = canvas.offsetHeight;
      }
    });
  },
};
</script>

<style>
.chart-container {
  display: flex;
  justify-content: center;
  align-items: center;
  height: 400px;
}
</style>