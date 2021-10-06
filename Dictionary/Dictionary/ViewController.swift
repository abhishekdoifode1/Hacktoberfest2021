//
//  ViewController.swift
//  Dictionary
//
//  Created by Sahil Tagunde on 14/10/19.
//  Copyright © 2019 sahiltagunde. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
   var dictionary = [String:String]()
    
    
    @IBOutlet weak var keyTextField: UITextField!
    @IBOutlet weak var valueTextField: UITextField!
    @IBAction func addButton(_ sender: Any) {
        
        
        dictionary = [keyTextField.text!:valueTextField.text!]
        
    }
    
    @IBOutlet weak var keySearchTextField: UITextField!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    
    }
    @IBAction func searchButton(_ sender: Any) {
        
        
        
        
    }
    
    @IBOutlet weak var displayLabel: UILabel!
    
}

