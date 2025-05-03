package chipyard

import org.chipsalliance.cde.config.{Config}
import constellation.channel._
import constellation.routing._
import constellation.topology._
import constellation.noc._
import constellation.soc.{GlobalNoCParams}
import scala.collection.immutable.ListMap
import chipyard.GemminiRocketConfig
import saturn.common.{VectorParams}


// Tutorial Phase 1: Configure the cores, caches
class RocketSaturnGemmini extends Config(
  // CUSTOMIZE THE CORE
  // Uncomment out one (or multiple) of the lines below, and choose
  // how many cores you want.
  // new boom.v3.common.WithNSmallBooms(1) ++  // Specify we want some number of BOOM cores

  
  new freechips.rocketchip.rocket.WithNHugeCores(1) ++    // Specify we want some number of Rocket cores  
  new freechips.rocketchip.subsystem.WithInclusiveCache(nWays=4, capacityKB=8192) ++ // CUSTOMIZE the L2 and specify a size if you want to have a L2
  new gemmini.GemminiCustomConfig ++   //new chipyard.GemminiRocketConfig ++
  new saturn.rocket.WithRocketVectorUnit(256, 128, VectorParams.minParams) ++ //Saturn VLEN = 256, DLEN = 128
  new chipyard.config.AbstractConfig  //Miscellaneuos system skeleton configuration
)


class RocketGemmini extends Config(
  // CUSTOMIZE THE CORE
  // Uncomment out one (or multiple) of the lines below, and choose
  // how many cores you want.
  new freechips.rocketchip.rocket.WithNHugeCores(1) ++    // Specify we want some number of Rocket cores
  // new boom.v3.common.WithNSmallBooms(1) ++                     // Specify we want some number of BOOM cores

  // CUSTOMIZE the L2
  // Uncomment this line, and specify a size if you want to have a L2
  new freechips.rocketchip.subsystem.WithInclusiveCache(nWays=4, capacityKB=8192) ++
  
  //new chipyard.GemminiRocketConfig ++
  new gemmini.GemminiCustomConfig ++ 
   
  //Saturn VLEN = 64
  //new saturn.rocket.WithRocketVectorUnit(64, 64, VectorParams.minParams) ++
  
  //Miscellaneuos
  new chipyard.config.AbstractConfig
)



  //Rocket + Saturn with different VLEN & DLEN. For example, WithRocketVectorUnit(256, 64, VectorParams.refParams) means VLEN = 256, DLEN = 64.
class MINV64D64RocketConfig extends Config(
  new saturn.rocket.WithRocketVectorUnit(64, 64, VectorParams.minParams) ++
  new freechips.rocketchip.rocket.WithNHugeCores(1) ++
  new chipyard.config.AbstractConfig)

class MINV128D64RocketConfig extends Config(
  new saturn.rocket.WithRocketVectorUnit(128, 64, VectorParams.minParams) ++
  new freechips.rocketchip.rocket.WithNHugeCores(1) ++
  new chipyard.config.AbstractConfig)

class MINV256D64RocketConfig extends Config(
  new saturn.rocket.WithRocketVectorUnit(256, 64, VectorParams.minParams) ++
  new freechips.rocketchip.rocket.WithNHugeCores(1) ++
  new chipyard.config.AbstractConfig)
  

 class MINV256D128RocketConfig extends Config(
  new saturn.rocket.WithRocketVectorUnit(256, 128, VectorParams.minParams) ++
  new freechips.rocketchip.rocket.WithNHugeCores(1) ++
  new chipyard.config.AbstractConfig)
  
  
  class MINV256D256RocketConfig extends Config(
  new saturn.rocket.WithRocketVectorUnit(256, 256, VectorParams.minParams) ++
  new freechips.rocketchip.rocket.WithNHugeCores(1) ++
  new chipyard.config.AbstractConfig)
  
  
  
  //Shuttle + Saturn with different VLEN & DLEN. For example, WithShuttleVectorUnit(256, 64, VectorParams.refParams) means VLEN = 256, DLEN = 64.
  class REFV256D64ShuttleConfig extends Config(
  new saturn.shuttle.WithShuttleVectorUnit(256, 64, VectorParams.refParams) ++
  new chipyard.config.WithSystemBusWidth(128) ++
  new shuttle.common.WithShuttleTileBeatBytes(16) ++
  new shuttle.common.WithNShuttleCores(1) ++
  new chipyard.config.AbstractConfig)

class REFV256D128ShuttleConfig extends Config(
  new saturn.shuttle.WithShuttleVectorUnit(256, 128, VectorParams.refParams) ++
  new chipyard.config.WithSystemBusWidth(128) ++
  new shuttle.common.WithShuttleTileBeatBytes(16) ++
  new shuttle.common.WithNShuttleCores(1) ++
  new chipyard.config.AbstractConfig)
  
class REFV256D256ShuttleConfig extends Config(
  new saturn.shuttle.WithShuttleVectorUnit(256, 256, VectorParams.refParams) ++
  new chipyard.config.WithSystemBusWidth(128) ++
  new shuttle.common.WithShuttleTileBeatBytes(16) ++
  new shuttle.common.WithNShuttleCores(1) ++
  new chipyard.config.AbstractConfig)
  

