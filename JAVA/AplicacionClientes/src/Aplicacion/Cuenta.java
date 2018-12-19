/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Aplicacion;

import java.io.Serializable;

/**
 *
 * @author t0p01
 */
public class Cuenta implements Serializable{
    private String ACCNumber;
    private double Money;

    public Cuenta() {
    }
    

    public String getACCNumber() {
        return ACCNumber;
    }

    public void setACCNumber(String ACCNumber) {
        this.ACCNumber = ACCNumber;
    }

    public double getMoney() {
        return Money;
    }

    public void setMoney(double Money) {
        this.Money = Money;
    }
    
    public void addMoney(double _Money){
        this.Money=this.Money+_Money;
    }
    public void withdrawM(double _Money){
        this.Money=this.Money-_Money;
    }

    @Override
    public String toString() {
        return "Cuenta{" + "Numero de Cuenta=" + ACCNumber + ", Saldo=" + Money + '}';
    }
    
    
}
