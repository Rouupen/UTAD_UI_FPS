# UTAD_UI_FPS


----Barra de vida del jugador----

He creado un delegado en el script del personaje y lo he vinculado en el método NativeConstruct de PlayerHealthBar. Cuando se llama al método SetHealth del personaje, se ejecuta el delegado y se actualiza el porcentaje de la barra de vida. También compruebo si el nuevo porcentaje de vida es menor que el threshold dado, y si lo es, cambio el color de la barra utilizando un contador de tiempo. Además, he añadido un lerp para que la actualización de la barra sea más suave.


----Crosshair----

He creado también un delegado en el script del personaje para detectar cuando el jugador dispara, el cual se ejecuta en el método Fire del UTP_WeaponComponent. Esto hace que el tamaño del crosshair aumente y luego con un lerp hago que vuelva a su tamaño original.

Para el color, he tenido que crear otra textura de color blanco para poder tintarla. Luego, en cada tick, lanzo un rayo en el forward vector de la cámara para saber si tengo un enemigo delante, y en base a eso cambio el color de la mira.

Además, he eliminado el crosshair del enemigo, ya que no le daba utilidad, y también he quitado la colisión de la barra de vida del enemigo, que hacía que se devolviera un valor incorrecto en el hit.


----Marcador de daño en pantalla----

He creado una nueva clase llamada PlayerHitMarker y un widget asociado a ella. Dentro del widget, he añadido una imagen de sangrado y le he puesto la opacidad a cero. Cuando el jugador recibe daño, desde el widget de la barra de vida, llamo al método ReceiveHit de esta clase y calculo la opacidad de la imagen en base al porcentaje de vida restante. Luego, ejecuto una animación que mantiene la imagen en pantalla por un tiempo antes de hacerla desaparecer.


----Pantalla splash----

He implementado esta pantalla de forma muy similar al marcador de daño en pantalla. He creado una clase llamada SplashScreen y lo he asociado a un widget. Luego, he reutilizado la animación de desaparición que tenía hecha para el daño en pantalla para que desaparezca y la llamo nada más empezar el juego.


----Árbol de habilidades/mejoras----

Para el menú de habilidades, he creado tres widgets. El primero es el menú principal donde se encuentran los botones en los que el jugador hará clic. Los otros dos widgets son popups: uno para aceptar la mejora y otro para notificar si no tienes puntos suficientes. Cuando se hace clic en uno de los botones, se verifica si tienes puntos suficientes y, en función de eso, se decide qué popup lanzar. El SkillTree es el que controla todo, y al que los botones llaman para indicarle el coste de cada habilidad.


----Extras----

He arreglado el contador de munición, la barra de vida de los enemigos y la barra de recarga


----Pregunta----

En el script de SkillTree.h, en la línea 38, he intentado referenciar los botones por referencia del editor. Me dejaba asignarlos al array, pero cuando compilaba perdía las referencias. ¿Existe alguna forma de hacerlo así, sin que pierda las referencias? Vengo de Unity y me resulta la forma más cómoda de hacerlo.