import React, { useState } from "react";
// import { useState } from "react";
import { Container, Row, Col } from "react-bootstrap";
// import { googleFormsToJson } from "react-google-forms-hooks";
import contactImg from "../assets/img/contact-img.svg";
import 'animate.css';
import TrackVisibility from 'react-on-screen';
// express cors nodemailer -> form contact submit

export const Contact = () => {
  const formInitialDetails = {
    firstName: '',
    lastName: '',
    email: '',
    phone: '',
    message: ''
  }
  const [formDetails, setFormDetails] = useState(formInitialDetails);
  const [buttonText, setButtonText] = useState('Send');
  const [status, setStatus] = useState({});

  const onFormUpdate = (category, value) => {
      setFormDetails({
        ...formDetails,
        [category]: value
      })
  }

  const handleSubmit = async (e) => {
    e.preventDefault();
    setButtonText("Sending...");
    let response = await fetch("http://localhost:5000/contact", {
      method: "POST",
      headers: {
        "Content-Type": "application/json;charset=utf-8",
      },
      body: JSON.stringify(formDetails),
    });
    setButtonText("Send");
    
    let result = await response.json();
    setFormDetails(formInitialDetails);
    if (result.code == 200) {
      setStatus({ succes: true, message: 'Message sent successfully'});
    } else {
      setStatus({ succes: false, message: 'Something went wrong, please try again later.'});
    }
  };

  return (
    <section className="contact" id="connect">
      <Container>
        <Row className="align-items-center">
          <Col size={12} md={6}>
            <TrackVisibility>
              {({ isVisible }) =>
                <img className={isVisible ? "animate__animated animate__zoomIn" : ""} src={contactImg} alt="Contact Us"/>
              }
            </TrackVisibility>
          </Col>
          <Col size={12} md={6}>
            <TrackVisibility>
              {({ isVisible }) =>
                <div className={isVisible ? "animate__animated animate__fadeIn" : ""}>
                <h2>Get In Touch</h2>
                <form onSubmit={handleSubmit}>
                  <Row>
                    <Col size={12} sm={6} className="px-1">
                      <input type="text" value={formDetails.firstName} placeholder="First Name" onChange={(e) => onFormUpdate('firstName', e.target.value)} />
                    </Col>
                    <Col size={12} sm={6} className="px-1">
                      <input type="text" value={formDetails.lasttName} placeholder="Last Name" onChange={(e) => onFormUpdate('lastName', e.target.value)}/>
                    </Col>
                    <Col size={12} sm={6} className="px-1">
                      <input type="email" value={formDetails.email} placeholder="Email Address" onChange={(e) => onFormUpdate('email', e.target.value)} />
                    </Col>
                    <Col size={12} sm={6} className="px-1">
                      <input type="tel" value={formDetails.phone} placeholder="Phone No." onChange={(e) => onFormUpdate('phone', e.target.value)}/>
                    </Col>
                    <Col size={12} className="px-1">
                      <textarea rows="6" value={formDetails.message} placeholder="Message" onChange={(e) => onFormUpdate('message', e.target.value)}></textarea>
                      <button type="submit"><span>{buttonText}</span></button>
                    </Col>
                    {
                      status.message &&
                      <Col>
                        <p className={status.success === false ? "danger" : "success"}>{status.message}</p>
                      </Col>
                    }
                  </Row>
                </form>
              </div>}
            </TrackVisibility>
          </Col>
        </Row>
      </Container>
    </section>
  )
}


const Form = () => {
  const [submit, setSubmit] = useState(false);
  const [formData, setFormData] = useState({
    "entry.2037917220": "",
    "entry.1146839265": "",
    "entry.1451219623": ""
  });

  const handleInputData = (input) => (e) => {
    const { value } = e.target;

    setFormData((prevState) => ({
      ...prevState,
      [input]: value
    }));
  };

  async function handleSubmit(e) {
    e.preventDefault();
    setSubmit(true);

    let url = `https://docs.google.com/forms/u/0/d/e/1FAIpQLSewQli5dBi0g1S8Ve-Bz6Xr7XP4W_27mBoVJwmftpsWTkFTVQ/formResponse?entry.2037917220=${formData["entry.2037917220"]}&entry.1146839265=${formData["entry.1146839265"]}&entry.1451219623=${formData["entry.1451219623"]}`;

    const res = await fetch(url, {
      method: "POST",
      headers: {
        "Content-Type": "application/x-www-form-urlencoded"
      }
    });
  }
  return (
    <div className="contactFormWrapper">
      <div className="formheader"></div>
      <div className="formcontact">
        {submit ? (
          <div className="afterForm">Thanks, will get back to you soon</div>
        ) : (
          <form onSubmit={handleSubmit} target="_self">
            <fieldset>
              <label htmlFor="entry.2037917220">Name:</label>
              <input
                required
                type="text"
                name="entry.2037917220"
                onChange={handleInputData("entry.2037917220")}
                value={formData["entry.2037917220"]}
                autoComplete={false}
              />
            </fieldset>

            <fieldset>
              <label htmlFor="entry.1146839265">E-mail:</label>
              <input
                required
                type="email"
                name="entry.1146839265"
                onChange={handleInputData("entry.1146839265")}
                value={formData["entry.1146839265"]}
                autoComplete={false}
              />
            </fieldset>

            <fieldset>
              <label htmlFor="entry.1451219623">Message:</label>
              <textarea
                required
                name="entry.1451219623"
                rows="4"
                cols="10"
                onChange={handleInputData("entry.1451219623")}
                value={formData["entry.1451219623"]}
                autoComplete={false}
              ></textarea>
            </fieldset>

            <button type="submit">Connect</button>
          </form>
        )}
      </div>
    </div>
  );
};


export const GoogleForm = () =>{
  const [submit, setSubmit] = useState(false);
  
  const [formData, setFormData] = useState({
    phone: "", //9911"">
    fName: "", //first" name">
    lName: "", //last" name">
    mes: "", //message"">
    email: "" //hi"@gmail.com">
  });

  const formMap = {
    phone: "entry.456044103", //9911"">
    fName: "entry.1964983302", //first" name">
    lName: "entry.2075805757", //last" name">
    mes: "entry.2089141021", //message"">
    email: "emailAddress" //hi"@gmail.com">
    // <input type="hidden" name="dlut" value="1717755279087">
    // <input type="hidden" name="hud" value="true">
  };

  const [buttonText, setButtonText] = useState('Send');
  const [status, setStatus] = useState({});

  const onFormUpdate = (key, e) => {
    setFormData((prevState) => ({
      ...prevState,
      [key]: e.target.value
    }));
  };
  
  const handleSubmit = async (e) => {
    e.preventDefault();
    setSubmit(true);

    let url2 = `https://docs.google.com/forms/u/0/d/e/1FAIpQLSewQli5dBi0g1S8Ve-Bz6Xr7XP4W_27mBoVJwmftpsWTkFTVQ/formResponse?entry.2037917220=${formData["entry.2037917220"]}&entry.1146839265=${formData["entry.1146839265"]}&entry.1451219623=${formData["entry.1451219623"]}`;
    let url = `https://docs.google.com/forms/u/0/d/e/1FAIpQLSdnOPO2v_Vis5X91Gn2cEyHoFR7m7eaQ3UB3eyRcW5ImXhZnQ/formResponse?${formMap.fName}=${formData.fName}&${formMap.lName}=${formData.lName}&${formMap.email}=${formData.email}&${formMap.phone}=${formData.phone}&${formMap.mes}=${formData.mes}`; 
    
    const res = await fetch(url, {
      method: "POST",
      headers: {
        "Content-Type": "application/x-www-form-urlencoded"
      }
    });
  }

  return (
    <section className="contact" id="connect">
      <Container>
        <Row className="align-items-center">
          <Col size={12} md={6}>
            <TrackVisibility>
              {({ isVisible }) =>
                <img className={isVisible ? "animate__animated animate__zoomIn" : ""} src={contactImg} alt="Contact Us"/>
              }
            </TrackVisibility>
          </Col>
          <Col size={12} md={6}>
            <TrackVisibility>
              {({ isVisible }) =>
                <div className={isVisible ? "animate__animated animate__fadeIn" : ""}>
                <h2>Get In Touch</h2>
                <form onSubmit={handleSubmit}>
                  <Row>
                    <Col size={12} sm={6} className="px-1">
                      <input 
                      type="text"
                      value={formDetails.firstName}
                      placeholder="First Name"
                      onChange={(e) => onFormUpdate("fName", e)} />
                    </Col>
                    <Col size={12} sm={6} className="px-1">
                      <input 
                      type="text"
                      value={formDetails.lasttName}
                      placeholder="Last Name"
                      onChange={(e) => onFormUpdate("lName", e)}/>
                    </Col>
                    <Col size={12} sm={6} className="px-1">
                      <input 
                      type="email"
                      value={formDetails.email}
                      placeholder="Email Address"
                      onChange={(e) => onFormUpdate("email", e)} />
                    </Col>
                    <Col size={12} sm={6} className="px-1">
                      <input 
                      type="tel"
                      value={formDetails.phone}
                      placeholder="Phone No."
                      onChange={(e) => onFormUpdate("phone", e)}/>
                    </Col>
                    <Col size={12} className="px-1">
                      <textarea 
                        rows="6" 
                        value={formDetails.message} 
                        placeholder="Message" 
                        onChange={(e) => onFormUpdate("mes", e)}></textarea>
                      <button type="submit"><span>{buttonText}</span></button>
                    </Col>
                    {
                      status.message &&
                      <Col>
                        <p className={status.success === false ? "danger" : "success"}>{status.message}</p>
                      </Col>
                    }
                  </Row>
                </form>
              </div>}
            </TrackVisibility>
          </Col>
        </Row>
      </Container>
    </section>
  );
}