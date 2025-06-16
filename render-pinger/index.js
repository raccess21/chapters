export default {
  async scheduled(event, env, ctx) {
    const urls = env.BACKEND_URL.split(";");
    
    for (const url of urls) {
      try {
        const pingurl = `${url}/ping?msg=keep_alive`;
        const response = await fetch(pingurl);
        console.log(`Pinged ${url}: ${response.status}`);
      } catch (error) {
        console.error("Ping failed:", error);
      }
    }
  }
};
