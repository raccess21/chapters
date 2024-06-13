import React, {useEffect, useRef} from "react";
import "./styles/Background.css";

const Background = () => {
    const videoRef = useRef(null);

    useEffect(() => {
        const handleScroll = () => {
            const video = videoRef.current;
            if (video) {
                const scrollTop = window.pageYOffset || document.documentElement.scrollTop; 
                const maxScrollTop = document.documentElement.scrollHeight - window.innerHeight;
                const scrollFraction = scrollTop / maxScrollTop;
                const videoDuration = video.duration;
                video.currentTime = scrollFraction * videoDuration;
            }
        };

        window.addEventListener("scroll", handleScroll);

        return() => {
            window.removeEventListener("scroll", handleScroll);
        };
    }, []);

    return (
        <div>

        <video 
            ref={videoRef} 
            className="background-video" 
            src="./assets/minions.mp4" 
            muted>
        </video>
        </div>
    );
};

export default Background;