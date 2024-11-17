# PF_ESP32_TEMP

Como se expone en el documento Proyecto Temperatuta.pdf, este proyecto surge para dar soulcion a una problematica de temperatura de la Universidad Cooperativa de Colombia, y asi mismo se propone que pofda ser utilizado en cualquier ambito donde la las altas temperaturas no sea favorables para el ambiente.

A continuacion encontrar como instalar y programar este dispositivo para su uso.

Como primer paso debemos de tener los siguientes componetes y cosas para inicar.

1.ESP32
2. Sensor de temperatura DHT22
3. Transistor NPN BC547
4. Relé de 5V
5. Ventilador de 5V
6. Dos resistencias (una de 220Ω para la base del transistor y, opcionalmente, una segunda de 1kΩ en el colector del transistor)
7. Jumpers y cables de conexión
8. Fuente de alimentación de 5V para el ventilador
9. Caja plastica o de madera 15x10 cm.
9. Blynk IoT instalada en su dispositivo movil.
10. Codigo ESP32 (ARCHIVO temp_blynk.io)
11. Cable USB a micro-USB.

1. Como primer paso para el desarrollo debemos de descargar el codigo fuente para que la ESP32 pueda empezar a recibir datos del sensor DHT11 y se conecte a nuestra red movil, por otro lado la funcion principal del codigo es conectarse a la plataforma Blynk.
2. Antes de introducir el codigo ya editado con su red movil, dirijase a la aplicacion Blynk IoT que encontrara tanto para dispositivos Android como para iOS, registrese con un correo y contraseña y seleccione el plan gratuito.
3. Dele click al "+" Ubicado en la parte derecha superior, y encontrara una opcion llama "Quickstart device", donde debera configurar las variables mostradas en el codigo como sera V1, V0, V2, V3 por las cuales el ESP32 enviara los datos y los asiganara a la grafica. Tabien tenha en cunetao que en cuanto selceccione esta opcion le brindara las credenciales necesarias para conectar sus dispositivos y que tendra que introudcir en el codigo "temp_blynk.ino"
4. Seleccione la opcion Customize de la parte superior derecha e introduzca una grafica que mejor se acople a uss gustos.
5. Ahora junto con la imagen "Diagrama Circuito PF.jpg" guiemos para conectar los dispositivos y empezar con el encendido del sistema:
  Conexiones Paso a Paso:
  1. Conectar el Sensor de Temperatura al ESP32
  VCC del Sensor ➔ 3.3V de la ESP32
  GND del Sensor ➔ GND de la ESP32
  Data del Sensor ➔ Conectar a un pin digital de la ESP32 (por ejemplo, D2)
  2. Conectar el Transistor NPN
  Emisor del transistor ➔ GND (común a todo el circuito).
  Colector ➔ Uno de los pines de entrada de la bobina del relé.
  Base ➔ Conectar a un pin GPIO de la ESP32 a través de una resistencia de 220Ω (esto podría ser el pin D5, por ejemplo).
  La resistencia de 220Ω en la base ayuda a limitar la corriente de activación para el transistor, protegiendo el pin GPIO de la ESP32.
  
  3. Conectar el Relé
  Conectar el otro pin de la bobina del relé ➔ 5V de la fuente de alimentación.
  GND de la fuente de 5V ➔ GND común del sistema (GND de la ESP32 y el emisor del transistor).
  Contacto COM del relé ➔ 5V de la fuente.
  Contacto NO (Normalmente Abierto) del relé ➔ Uno de los pines del ventilador.
  Cuando el transistor activa el relé, este cerrará el circuito entre los 5V y el ventilador.
  
  4. Conectar el Ventilador
  Conectar uno de los pines del ventilador ➔ Contacto NO del relé.
  El otro pin del ventilador ➔ GND de la fuente de 5V.
  El ventilador estará conectado en un circuito de 5V separado de la ESP32, y el relé lo encenderá cuando la temperatura esté alta.
  
  5. GND Común
  Asegúrate de que todos los componentes compartan una conexión a GND común para que el circuito funcione correctamente.
6. Posteriormente junto con un cable USB a micro-USB conecte su computadora con las credentiales de Blynk Iot y su red movil en archivo temp_blynk.ino en Arduino y compile este codigo dentro de la ESP32.
7. Con los anterior su sistema de monitoreo de temperatura con un ventilador deberia de funcionar, ahora bien junto con la Caja del material escogido 15x10 cm introduzca con mucho cuidado junto con tornillos o abrazaderas ajuste el DHT22 y el ventilador a la caja.

Esto seria todo. Revise material visual si necesita soporte.

================================================================================================================================================================

# PF_ESP32_TEMP

As stated in the document Proyecto Temperatuta.pdf, this project arises to give solution to a temperature problem at the Universidad Cooperativa de Colombia, and it is also proposed that it can be used in any environment where high temperatures are not favorable for the environment.

Below you will find how to install and program this device for use.

As a first step we must have the following components and things to start with.

1.ESP32
2. DHT22 temperature sensor
3. BC547 NPN transistor
4. 5V relay
5. 5V fan
6. Two resistors (one of 220Ω for the base of the transistor and, optionally, a second of 1kΩ in the collector of the transistor)
7. Jumpers and connection cables
8. 5V power supply for the fan
9. Plastic or wooden box 15x10 cm.
9. Blynk IoT installed on your mobile device.
10. ESP32 code (FILE temp_blynk.io)
11. USB to micro-USB cable.

1. As a first step for development we must download the source code so that the ESP32 can start receiving data from the DHT11 sensor and connect to our mobile network, on the other hand the main function of the code is to connect to the Blynk platform.
2. Before entering the already edited code with your mobile network, go to the Blynk IoT application that you will find for both Android and iOS devices, register with an email and password and select the free plan.
3. Click on the "+" located on the top right, and you will find an option called "Quickstart device", where you must configure the variables shown in the code such as V1, V0, V2, V3 through which the ESP32 will send the data and assign it to the graph. Also keep in mind that as soon as you select this option it will give you the necessary credentials to connect your devices and that you will have to enter them in the code "temp_blynk.ino"
4. Select the Customize option on the top right and enter a graphic that best suits your tastes.
5. Now, along with the image "PF Circuit Diagram.jpg" we will guide you to connect the devices and start turning on the system:
Step by Step Connections:
1. Connect the Temperature Sensor to the ESP32
VCC of the Sensor ➔ 3.3V of the ESP32
GND of the Sensor ➔ GND of the ESP32
Data of the Sensor ➔ Connect to a digital pin of the ESP32 (for example, D2)
2. Connect the NPN Transistor
Transistor emitter ➔ GND (common to the entire circuit).
Collector ➔ One of the relay coil input pins.
Base ➔ Connect to a GPIO pin on the ESP32 via a 220Ω resistor (this could be pin D5, for example).
The 220Ω resistor on the base helps limit the trigger current for the transistor, protecting the ESP32 GPIO pin.

3. Connect the Relay
Connect the other pin of the relay coil ➔ 5V from the power supply.
GND of the 5V supply ➔ Common GND of the system (GND of the ESP32 and the emitter of the transistor).
COM contact of the relay ➔ 5V from the supply.
NO (Normally Open) contact of the relay ➔ One of the fan pins.
When the transistor activates the relay, it will close the circuit between the 5V and the fan.

4. Connect the Fan
Connect one of the fan pins ➔ NO contact of the relay.
The other pin of the fan ➔ GND of the 5V source.
The fan will be connected in a separate 5V circuit from the ESP32, and the relay will turn it on when the temperature is high.

5. Common GND
Make sure that all components share a common GND connection for the circuit to work correctly.

6. Then, with a USB to micro-USB cable, connect your computer with the Blynk IoT credentials and your mobile network in the temp_blynk.ino file in Arduino and compile this code inside the ESP32.
7. With the above, your temperature monitoring system with a fan should work, now together with the Box of the chosen material 15x10 cm, carefully insert it with screws or clamps and adjust the DHT22 and the fan to the box.

That would be all. Check the visual material if you need support.
