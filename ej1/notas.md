# Cosas que hice que no estan en el diagrama

- agregarDepartamento() para Empresa
- agregarPais() para CentralRegional (quedaba feo insertar en el set)
- agregarGerenteAlto() y agregarGerenteMedio() para CentralRegional
- agregarEmpresa() para CentralRegional

# Dudas de que penso marianito

- Para que sirve la subentidad en EntidadOrganizativa? Y en general para que sirve EntidadOrganizativa?
- Porque no existe un agregarDepartamento() en Empresa?
- Porque no existe un agregarEmpresa() en CentralRegional?
- GerenteBajo y LiderEquipo no los uso nunca?
- Porque contarEmpleados() es static?
- Porque getSalario() es privado?
- Tengo que tener en cuenta los empleados de cada Departamento asignados a la central regional para calcular la cantidad de empleados en la central regional?