import React from 'react'

import { controls } from './buttons/list'

class Actions extends React.Component {
  render() {
    return (
      <ul className="list-unstyled">
        <li className="list-inline-item"><button id="control"><img src={controls.left.img} alt={controls.right.action} />{controls.left.action}</button></li>
        <li className="list-inline-item"><button id="control"><img src={controls.right.img} alt={controls.right.action} />{controls.right.action}</button></li>
        <li className="list-inline-item"><button id="control"><img src={controls.angry.img} alt={controls.right.action} />{controls.angry.action}</button></li>
        <li className="list-inline-item"><button id="control"><img src={controls.waggle.img} alt={controls.right.action} />{controls.waggle.action}</button></li>
      </ul>
    )
  }
}

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <div className="button">
          <ul className="list-unstyled">
            <Actions />
          </ul>
        </div>
      </header>
    </div>
  )
}

export default App