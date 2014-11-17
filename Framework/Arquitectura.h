#if !defined ARQUITECTURA_H
#define ARQUITECTURA_H

/*!Esta clase se utiliza para definir la arquitectura del genetico.*/
class Arquitectura
{
public:
		/*!Constructor por defecto.*/
		Arquitectura();
		/*!Constructor por defecto con argumentos.
			\param evaluacion Porcentaje de la Poblacion que se evaluara.
			\param seleccion Porcentaje de la Poblacion que se seleccionara.
			\param cruzamiento Porcentaje de la Poblacion que se cruzara.
			\param mutacion Porcentaje de la Poblacion que se mutara.
			\param elites Porcentaje de la Poblacion que se utilizara como individuos elites.
		*/
		Arquitectura(int evaluacion, int seleccion, int cruzamiento, int mutacion, int elites);
		/*!Destructor virtual*/
		virtual ~Arquitectura();
		/*!Retorna el porcentaje de la Poblacion destinado a ser evaluado.
			\return El porcentaje de evaluacion.
		*/
        int getPorcentajeEvaluacion();
		/*!Retorna el porcentajArquitecturae de la Poblacion destinado a ser seleccionado.
			\return El porcentaje de seleccion.
		*/
        int getPorcentajeSeleccion();
		/*!Retorna el porcentaje de la Poblacion destinado a ser cruzado.
			\return El porcentaje de cruzamiento.
		*/
        int getPorcentajeCruzamiento();
		/*!Retorna el porcentaje de la Poblacion destinado a ser mutado.
			\return El porcentaje de mutacion.
		*/
        int getPorcentajeMutacion();
		/*!Retorna el porcentaje de la Poblacion destinado a ser usado como individuos elites.
			\return El porcentaje de elites.
		*/
        int getPorcentajeElite();
		/*!Establece el porcentaje de la Poblacion destinado a ser evaluado.
			\param porcentaje El porcentaje de evaluacion.
		*/
        void setPorcentajeEvaluacion(int porcentaje);
		/*!Establece el porcentaje de la Poblacion destinado a ser seleccionado.
			\param porcentaje El porcentaje de seleccion.
		*/
        void setPorcentajeSeleccion(int);
		/*!Establece el porcentaje de la Poblacion destinado a ser cruzado.
			\param porcentaje El porcentaje de cruzamiento.
		*/
        void setPorcentajeCruzamiento(int);
		/*!Establece el porcentaje de la Poblacion destinado a ser mutado.
			\param porcentaje El porcentaje de mutacion.
		*/
        void setPorcentajeMutacion(int);
		/*!Establece el porcentaje de la Poblacion destinado a ser usado como individuos elites.
			\param porcentaje El porcentaje de elites.
		*/
        void setPorcentajeElite(int);

private:
		int porcentajeEvaluacion;
		int porcentajeSeleccion;
		int porcentajeCruzamiento;
		int porcentajeMutacion;
		int porcentajeElite;

};
#endif // !defined ARQUITECTURA_H
