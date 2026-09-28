# Sistema de Gestión de Medallero Olímpico (C++)

Aplicación de consola desarrollada en C++ para la administración, registro y análisis estadístico de resultados en disciplinas deportivas olímpicas, con control de acceso de usuarios y persistencia de datos.

## 📌 Descripción del Proyecto
El sistema permite a usuarios registrados gestionar un medallero olímpico interactivo, centralizando la carga de resultados de delegaciones por país y disciplina, además de generar reportes estadísticos avanzados sobre el rendimiento en la competencia.

## 🚀 Funcionalidades Principales
* **Autenticación y Seguridad:** Módulo de inicio de sesión (`logIn`) con validación de credenciales para usuarios registrados.
* **Gestión de Disciplinas:** Registro y configuración de deportes y cronogramas de competencias.
* **Carga de Medallero:** Registro estructurado de medallas (Oro, Plata, Bronce) asociadas a países y participantes.
* **Motor de Estadísticas:** Algoritmos de cálculo para generar rankings de países, tablas de posiciones y estadísticas deportivas.
* **Persistencia de Datos:** Almacenamiento en archivos locales para conservar registros y resultados entre sesiones.

## 🛠️ Tecnologías y Estructuras Utilizadas
* **Lenguaje:** C++ (Estándar C++11 o superior).
* **Paradigma:** Modular y Estructurado.
* **Estructuras de Datos:** Manejo de matrices/vectores para cómputo de posiciones y parsing de archivos.
* **Entorno de compilación:** GCC / MinGW.

## 📂 Arquitectura del Código
```text
├── src/ (o directorio raíz)
│   ├── archivo.cpp / archivo.h             # Lectura y escritura de datos
│   ├── bienvenida.cpp / bienvenida.h       # Pantalla de bienvenida y contexto
│   ├── logIn.cpp                           # Validación y acceso
│   ├── deportes.cpp                        # Administración de disciplinas
│   ├── generarCompetencia.cpp              # Lógica de emparejamiento y eventos
│   ├── cargarMedallas.cpp                  # Registro y asignación de medallas
│   ├── estadisticas.cpp                    # Algoritmos de ordenamiento y rankings
│   └── main.cpp                            # Punto de entrada y flujo del menú
├── .gitignore
└── README.md