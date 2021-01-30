Para importar las reglas en Thingsboard se han separado en tres archivos diferentes:

  - root_rule_chain.json: se considera fichero main de las reglas, contiene la llamada
  a las alarmas y las reglas básicas para recibir los datos y almacenarlos. Se importa en la
  sección de Rule Chains.
  - alarmas.json: este fichero contiene las alarmas configuradas para nuestro ejemplo, 
  también contiene la configuración de un bot de Telegram que envía estos avisos. Se importa
  en la sección de Rule Chains.
  - jard_n_vertical.json: este fichero contiene la configuración del Dashboard para poder 
  visualizar los datos recibidos por el dispositivo ESP32. Este archivo se importa en la
  sección de Dashboard.

Dependiendo del dispositivo y los valores a los que hayas ajustado tus medidas, es posible
que haya que modificar algunos valores y el id de Telegram. Se pueden modificar simplemente
en la interfaz de Thingsboard.
