#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import pandas as pd
import ipywidgets as widgets

import plotly.graph_objects as go
from plotly.subplots import make_subplots

from IPython.display import clear_output, display


# In[8]:


#Ploting
def graficar_tabla(data,graf):
    fig = make_subplots(
        rows=2, cols=1,
        shared_xaxes=False,
        vertical_spacing=0.03,
        specs=[[{"type": "table"}],
               [{"type": "scatter"}]]
        
    )
    fig.add_trace(
        go.Table(
            header=dict(
                values=data.columns,
                font=dict(size=10),
                align="left"
            ),
            cells=dict(
                values=[data[k].tolist() for k in data.columns],
                align = "left")
        ),
        row=1, col=1
    )
    
    fig.add_trace(
        go.Scatter(
            x=graf["T"],
            y=graf["V"],
            mode="lines",
            name="Velocidad"
        ),row=2, col=1)
    
    fig.add_trace(
        go.Scatter(
            x=graf["T"],
            y=graf["X"],
            mode="lines",
            name="Posición"
        ),row=2, col=1)
    
    fig.add_trace(
        go.Scatter(
            x=graf["T"],
            y=graf["A"],
            mode="lines",
            line_shape='hv',
            name="Aceleración"
        ),row=2, col=1)
    
    fig.update_layout(
        #height=800,
        #showlegend=False,
        title_text="Resultado",
    )
    clear_output()
    display(tab)
    fig.show()


# In[3]:


#Data Science
def Aceleración(x,y):
    data = pd.DataFrame()
    return data

def Velocidad(x,y):
    data = pd.DataFrame()
    graf = pd.DataFrame()
    #Los tiempos
    data["To"] = x[:-1]
    data["Tf"] = x[1:]
    
    graf["T"] = x
    
    #Cambio de tiempos
    data["dT"] = np.diff(x)
    
    #Las velocidads
    data["Vo"] = y[:-1]
    data["Vf"] = y[1:]
    
    graf["V"] = y
    
    #Cambio de velocidades
    data["dV"] = np.diff(y)
    
    #Velocidad Promedio
    data["Vp"] = (y[:-1] + y[1:]) / 2
    
    #Cambio de posición
    data["dX"] = data["dT"] * data["Vp"]
    
    #Calculamos Xo y Xf
    data["Xo"] = inicial.value
    data["Xf"] = data["dX"] + data["Xo"]
    
    for i in range(1,len(data)):
        data["Xo"][i] = data["Xf"][i - 1]
        data["Xf"][i] = data["dX"][i] + data["Xo"][i]
        
    graf["X"] = data["Xo"]
    graf['X'][-1:] = float(data["Xf"][-1:])
        
    #Calculamos la aceleración
    data["a"] = data["dV"] / data["dT"]
    
    graf["A"] = data["a"]
    graf['A'][-1:] = 0
    
    return data, graf

def Posición(x,y):
    data = pd.DataFrame()
    return data

def data_formula():
    tabular_para = {'Aceleración':Aceleración,'Velocidad':Velocidad,'Posición':Posición}
    funcion = formula.value
    x = np.arange(float(inicio.value),float(final.value),float(pasos.value))
    y = eval(f"{funcion}")
    data, graf = tabular_para[tipo.value](x,y)
    graficar_tabla(data,graf)
    
def data_arb():
    tabular_para = {'Aceleración':Aceleración,'Velocidad':Velocidad,'Posición':Posición}
    x = np.array(posiciones.value.split(',')).astype(np.float)
    y = np.array(valores.value.split(',')).astype(np.float)
    data, graf = tabular_para[tipo.value](x,y)
    graficar_tabla(data,graf)


# In[4]:


#Widgets de la formula
inicio = widgets.FloatText(
    value=0,
    description='Inicio:',
)

final = widgets.FloatText(
    value=10,
    description='Final:',
)

pasos = widgets.FloatText(
    value=1,
    description='Pasos:',
)

inicial = widgets.FloatText(
    value=0,
    description='Pos Inicial',
    disabled =False
)

formula = widgets.Text(
    value="x**2",
    description='Formula:'
)


# In[5]:


#Widgets arbitrarios
posiciones = widgets.Text(
    value="X1, X2, X3, ...",
    description='Posiciones:'
)

valores = widgets.Text(
    value="Y1, Y2, Y3, ...",
    description='Valores:'
)


# In[6]:


#Widgets generales
def get_data(_):
    procedimiento = {0:data_formula,1:data_arb}
    procedimiento[tab.selected_index]()
    
tipo = widgets.Dropdown(
    options=['Aceleración', 'Velocidad', 'Posición'],
    value='Velocidad',
    description='Grafica:',
)

graficar = widgets.Button(
    description='Graficar',
    button_style='success', # 'success', 'info', 'warning', 'danger' or ''
    tooltip='Graficar',
    icon='check' # (FontAwesome names without the `fa-` prefix)
)

graficar.on_click(get_data)


# In[9]:


#Tab
por_formula = widgets.GridBox([inicio, final, pasos,inicial,tipo,formula, graficar],layout=widgets.Layout(grid_template_columns="repeat(2, 50%)"))
arbitrario = widgets.GridBox([posiciones, valores,inicial, tipo, graficar],layout=widgets.Layout(grid_template_columns="repeat(2, 50%)"))
tab = widgets.Tab()
tab.children = [por_formula, arbitrario]

for i, title in enumerate(['Formula', 'Arbritario']):
    tab.set_title(i,title)
    
display(tab)


# In[ ]:




